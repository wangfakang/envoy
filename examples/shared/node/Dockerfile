FROM node:21.2-bullseye-slim@sha256:cc16ec9e9a785fe0a185ac07d121327fd0efe4f588a55297362a5d4a9a347013 as node-base


FROM node-base as node-http-auth
ARG NODE_APP=.
ARG NODE_APP_NAME=http-service/server
# Add an env to save ARG
ENV NODE_APP_PATH "/app/${NODE_APP_NAME}"
COPY "$NODE_APP" /app
# Dont use exec form to interpolate correctly
CMD node $NODE_APP_PATH
