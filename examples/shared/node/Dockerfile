FROM node:22.9-bullseye-slim@sha256:80c9b96d59e83fa41e14e3d90953d52a875a60447efb74469cb195f0e64457bc as node-base


FROM node-base as node-http-auth
ARG NODE_APP=.
ARG NODE_APP_NAME=http-service/server
# Add an env to save ARG
ENV NODE_APP_PATH "/app/${NODE_APP_NAME}"
COPY "$NODE_APP" /app
# Dont use exec form to interpolate correctly
CMD node $NODE_APP_PATH
