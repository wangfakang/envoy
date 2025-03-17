FROM node:23.10-bullseye-slim@sha256:5e50aac757e917aaaf5cc4c38462155725cae4375d49ecba8e5ee4584644ee7f as node-base


FROM node-base as node-http-auth
ARG NODE_APP=.
ARG NODE_APP_NAME=http-service/server
# Add an env to save ARG
ENV NODE_APP_PATH "/app/${NODE_APP_NAME}"
COPY "$NODE_APP" /app
# Dont use exec form to interpolate correctly
CMD node $NODE_APP_PATH
